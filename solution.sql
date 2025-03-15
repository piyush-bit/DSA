Question - 1

-- First, let's create a CTE (Common Table Expression) to calculate total invoice amounts
WITH InvoiceTotals AS (
    SELECT 
        i.INV_NUMBER,
        i.CUS_CODE,
        SUM(l.LINE_UNITS * l.LINE_PRICE) as TOTAL_AMOUNT
    FROM INVOICE i
    JOIN LINE l ON i.INV_NUMBER = l.INV_NUMBER
    GROUP BY i.INV_NUMBER, i.CUS_CODE
    HAVING SUM(l.LINE_UNITS * l.LINE_PRICE) > 100
)

-- Now join with CUSTOMER and INVOICE tables to get the required information
SELECT 
    i.INV_NUMBER,
    c.CUS_CODE,
    c.CUS_FNAME + ' ' + c.CUS_LNAME as CUSTOMER_NAME,
    i.INV_DATE,
    it.TOTAL_AMOUNT as INVOICE_AMOUNT
FROM InvoiceTotals it
JOIN INVOICE i ON it.INV_NUMBER = i.INV_NUMBER
JOIN CUSTOMER c ON i.CUS_CODE = c.CUS_CODE
ORDER BY i.INV_NUMBER;


OUTPUT
INV_NUMBER  CUS_CODE    CUSTOMER_NAME                   INV_DATE                INVOICE_AMOUNT                          
----------- ----------- ------------------------------- ----------------------- ----------------------------------------
       1003       10012 Kathy Smith                     2014-01-16 00:00:00.000                                 153.8500
       1006       10014 Myron Orlando                   2014-01-17 00:00:00.000                                 397.8300
       1008       10011 Leona Dunne                     2014-01-17 00:00:00.000                                 399.1500


Question - 2

WITH InvoiceAmounts AS (
    -- Calculate the amount for each invoice
    SELECT 
        i.INV_NUMBER,
        i.CUS_CODE,
        i.INV_DATE,
        SUM(l.LINE_UNITS * l.LINE_PRICE) as INVOICE_AMOUNT
    FROM INVOICE i
    JOIN LINE l ON i.INV_NUMBER = l.INV_NUMBER
    GROUP BY i.INV_NUMBER, i.CUS_CODE, i.INV_DATE
),
AverageAmount AS (
    -- Calculate the overall average invoice amount
    SELECT AVG(INVOICE_AMOUNT) as AVG_INVOICE_AMOUNT
    FROM InvoiceAmounts
)
-- Final query comparing each invoice to the average
SELECT 
    ia.INV_NUMBER,
    ia.CUS_CODE,
    c.CUS_FNAME + ' ' + c.CUS_LNAME as CUSTOMER_NAME,
    ia.INV_DATE,
    ia.INVOICE_AMOUNT,
    avg.AVG_INVOICE_AMOUNT as AVERAGE_INVOICE_AMOUNT,
    ia.INVOICE_AMOUNT - avg.AVG_INVOICE_AMOUNT as DIFFERENCE_FROM_AVERAGE
FROM InvoiceAmounts ia
CROSS JOIN AverageAmount avg
JOIN CUSTOMER c ON ia.CUS_CODE = c.CUS_CODE
ORDER BY ia.INV_NUMBER;


INV_NUMBER  CUS_CODE    CUSTOMER_NAME                   INV_DATE                INVOICE_AMOUNT                           AVERAGE_INVOICE_AMOUNT                   DIFFERENCE_FROM_AVERAGE                 
----------- ----------- ------------------------------- ----------------------- ---------------------------------------- ---------------------------------------- ----------------------------------------
       1001       10014 Myron Orlando                   2014-01-16 00:00:00.000                                  24.9400                               140.753750                                -115.8138
       1002       10011 Leona Dunne                     2014-01-16 00:00:00.000                                   9.9800                               140.753750                                -130.7738
       1003       10012 Kathy Smith                     2014-01-16 00:00:00.000                                 153.8500                               140.753750                                  13.0963
       1004       10011 Leona Dunne                     2014-01-17 00:00:00.000                                  34.8700                               140.753750                                -105.8838
       1005       10018 Anne Farriss                    2014-01-17 00:00:00.000                                  70.4400                               140.753750                                 -70.3138
       1006       10014 Myron Orlando                   2014-01-17 00:00:00.000                                 397.8300                               140.753750                                 257.0763
       1007       10015 Amy O'Brian                     2014-01-17 00:00:00.000                                  34.9700                               140.753750                                -105.7838
       1008       10011 Leona Dunne                     2014-01-17 00:00:00.000                                 399.1500                               140.753750                                 258.3963
'

Q3.

-- 1. Modify INVOICE and LINE tables to add ACTIVE attribute
ALTER TABLE INVOICE
ADD ACTIVE BIT DEFAULT 1;

ALTER TABLE LINE
ADD ACTIVE BIT DEFAULT 1;

-- Update existing records to set ACTIVE = 1
UPDATE INVOICE SET ACTIVE = 1;
UPDATE LINE SET ACTIVE = 1;

-- 2. Create procedure to "delete" (deactivate) an invoice
CREATE PROCEDURE DELETE_INVOICE
    @INV_NUMBER INTEGER
AS
BEGIN
    -- Check if invoice exists
    IF EXISTS (SELECT 1 FROM INVOICE WHERE INV_NUMBER = @INV_NUMBER)
    BEGIN
        -- Begin transaction to ensure both tables are updated
        BEGIN TRANSACTION
            -- Update INVOICE table
            UPDATE INVOICE
            SET ACTIVE = 0
            WHERE INV_NUMBER = @INV_NUMBER;

            -- Update LINE table
            UPDATE LINE
            SET ACTIVE = 0
            WHERE INV_NUMBER = @INV_NUMBER;
            
        -- If we got here without errors, commit the transaction
        COMMIT TRANSACTION
        PRINT 'Invoice ' + CAST(@INV_NUMBER AS VARCHAR) + ' and its line items have been deactivated successfully.';
    END
    ELSE
    BEGIN
        PRINT 'Invoice ' + CAST(@INV_NUMBER AS VARCHAR) + ' does not exist.';
    END
END;

-- 3. Create procedure to restore an invoice
CREATE PROCEDURE RESTORE_INVOICE
    @INV_NUMBER INTEGER
AS
BEGIN
    -- Check if invoice exists
    IF EXISTS (SELECT 1 FROM INVOICE WHERE INV_NUMBER = @INV_NUMBER)
    BEGIN
        -- Begin transaction to ensure both tables are updated
        BEGIN TRANSACTION
            -- Update INVOICE table
            UPDATE INVOICE
            SET ACTIVE = 1
            WHERE INV_NUMBER = @INV_NUMBER;

            -- Update LINE table
            UPDATE LINE
            SET ACTIVE = 1
            WHERE INV_NUMBER = @INV_NUMBER;
            
        -- If we got here without errors, commit the transaction
        COMMIT TRANSACTION
        PRINT 'Invoice ' + CAST(@INV_NUMBER AS VARCHAR) + ' and its line items have been restored successfully.';
    END
    ELSE
    BEGIN
        PRINT 'Invoice ' + CAST(@INV_NUMBER AS VARCHAR) + ' does not exist.';
    END
END;


