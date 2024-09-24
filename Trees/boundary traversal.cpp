                            

class Node {
    constructor(val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

class Solution {

    isLeaf(root) {
        return !root.left && !root.right;
    }


    addLeftBoundary(root, res) {
        let curr = root.left;
        while (curr) {
            if (!this.isLeaf(curr)) {
                res.push(curr.data);
            }
          
            if (curr.left) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
    }

    addRightBoundary(root, res) {
        let curr = root.right;
        let temp = [];
        while (curr) {

            if (!this.isLeaf(curr)) {
                temp.push(curr.data);
            }
   
            if (curr.right) {
                curr = curr.right;
            } else {
                curr = curr.left;
            }
        }
      
        for (let i = temp.length - 1; i >= 0; --i) {
            res.push(temp[i]);
        }
    }


    addLeaves(root, res) {
      
        if (this.isLeaf(root)) {
            res.push(root.data);
            return;
        }
       
        if (root.left) {
            this.addLeaves(root.left, res);
        }
        if (root.right) {
            this.addLeaves(root.right, res);
        }
    }

    printBoundary(root) {
        let res = [];
        if (!root) {
            return res;
        }
        
        if (!this.isLeaf(root)) {
            res.push(root.data);
        }

      
        this.addLeftBoundary(root, res);
        this.addLeaves(root, res);
        this.addRightBoundary(root, res);

        return res;
    }
}

// Helper function to print the result
function printResult(result) {
    for (let val of result) {
        console.log(val + " ");
    }
    console.log();
}
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

let solution = new Solution();


let result = solution.printBoundary(root);

console.log("Boundary Traversal: ");
printResult(result);

                            
                        
