/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSum = function(nums) {
    let sum=0;
    const freq = new Map();

    for(let num of nums){
        if(num>0 && (!freq.has(num))){
            freq.set(num);
            sum+=num;
        }
    }
    if(sum===0){
        sum=Math.max(...nums);
    }
    return sum;
};

const nums = [4,2,1,6,3,5];
const result=maxSum(nums);
console.log("Maximum Unique Subarray Sum:", result);