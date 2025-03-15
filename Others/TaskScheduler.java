import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Stack;

class Solution {
    public int leastInterval(char[] tasks, int n) {

        int[] freq = new int[26];
        for (int i = 0; i < tasks.length; i++) {
            freq[tasks[i] - 'A']++;
        }

        int[] lastOccur = new int[26];
        for (int i = 0; i < 26; i++) {
            lastOccur[i] = -1;
        }

        int taskTypeCount = 26;
        int currentPlace = 0;
        while (taskTypeCount > 0) {
            taskTypeCount = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {

                    if (lastOccur[i] == -1) {
                        lastOccur[i] = currentPlace;
                        currentPlace++;
                        freq[i]--;
                    } else if (currentPlace - lastOccur[i] <= n) {
                        currentPlace = lastOccur[i] + 1 + n;
                        lastOccur[i] = currentPlace;
                        currentPlace++;
                        freq[i]--;
                    } else {
                        lastOccur[i] = currentPlace;
                        currentPlace++;
                        freq[i]--;
                    }
                    taskTypeCount++;
                }

            }
        }

        return currentPlace;

    }

    int compare(Task o1, Task o2) {
        if(o1.freq == o2.freq){
            return o1.lastOccur - o2.lastOccur ;
        }
        return o2.freq - o1.freq;
    }

    public int leastInterval2(char[] tasks, int n) {
        PriorityQueue < Task > pq = new PriorityQueue<>((o1, o2) -> compare(o1, o2));

        int [] freq = new int[26];  

        for(int i = 0 ; i < tasks.length ; i++){
            freq[tasks[i] - 'A']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] > 0){
                pq.add(new Task(freq[i] , i , -1));
            }
        }
        int currentPlace = 0 ; 


        while(!pq.isEmpty()){
            
            Task p = pq.poll();
            if(p.lastOccur==-1){
                p.freq--;
                p.lastOccur = currentPlace;
                currentPlace++;
            }else if(currentPlace - p.lastOccur <= n){
                p.freq--;
                
            }else{
                
            }
            
            


        }
        

        return 0 ;
    }
}

class Task {
    int charValue, freq , lastOccur ;
    Task(int charValue , int freq , int lastOccur){
        this.charValue = charValue;
        this.freq = freq;
        this.lastOccur = lastOccur ;
    }
}
