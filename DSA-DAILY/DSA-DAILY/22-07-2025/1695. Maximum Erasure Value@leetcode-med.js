/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
    let seen=new Set();
    let s=0,currs=0,res=0;
    for(let i=0;i<nums.length;i++){
        while(seen.has(nums[i])){
            currs-=nums[s];
            seen.delete(nums[s]);
            s++;
        }
        currs+=nums[i];
        seen.add(nums[i]);
        res=Math.max(res,currs);
    }
    return res;
};

/** 
 * const  nums = [4, 2, 4, 5, 6];
 * const result =maximumUniqueSubarray(nums);
 * console.log("Input array: ",nums);
 * console.log("Maximum Erasable Vaule :",result);
 */

const readline=require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question('Enter the array elements seperated by space: ', input=>{
    const nums=input.trim().split(/\s+/).map(Number);
    const result =maximumUniqueSubarray(nums);
    console.log("Intput array: ",nums);
    console.log("Maximum Ereasable Value: ",result);
    readline.close();
});