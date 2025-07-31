/**
 * @param {number[]} arr
 * @return {number}
 */
var subarrayBitwiseORs = function(arr) {
    const res=new Set();
    const n = arr.length;

    for(let i=0;i<n;i++){
        res.add(arr[i]);
        let curr=arr[i];
        for(let j=i-1; j>=0; j--){
            if((arr[j]|curr) === arr[j])break;
            arr[j] |= curr;
            res.add(arr[j]);
        }
    }
    return res.size
};

const readInput = () => {
    const input = prompt("Enter an array of numbers separated by commas:");
    const arr = input.split(",").map(Number);
    return arr;
};

const main = () => {
    const arr = readInput();
    const result = subarrayBitwiseORs(arr);
    console.log("Number of distinct bitwise ORs:", result);
};
