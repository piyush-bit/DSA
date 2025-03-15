import java.util.Stack;

public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        normalize(root,0);
        // level oder traversal 
        Stack <TreeNode> stack = new Stack<>();
        stack.push(root);
        int ans = 0;
        while(!stack.isEmpty()){
            int size = stack.size();
            int min = Integer.MAX_VALUE;
            int max = 0;

            for(int i=0;i<size;i++){
                TreeNode node = stack.pop();
                min = Math.min(min,node.val);
                max = Math.max(max,node.val);
                if(node.left!=null)
                stack.push(node.left);
                if(node.right!=null)
                stack.push(node.right);
            }   
            System.out.println(min+" "+max);
            ans = Math.max(ans,max-min+1);  
        }
        return ans;
        
    }

    void normalize(TreeNode root,int number){
          if(root==null)
          return;

          root.val=number;
          normalize(root.left,2*number);
          normalize(root.right,2*number+1);
    }
}