/**
 * @param {number[]} nums
 * @param {int} maxi
 * @param {int} curr
 * @param {int} ind 
 * @return {number}
 */

function backtrack(nums,maxi,ind,curr){
    if(ind==nums.length){
        return (curr==maxi)?1:0;
    }
    if(curr==maxi){
        return 1<<(nums.length-ind);
    }
    let consider=backtrack(nums,maxi,ind+1,curr|nums[ind]);
    let notconsider=backtrack(nums,maxi,ind+1,curr);
    return consider+notconsider;
} 

var countMaxOrSubsets = function(nums) {
    let maxi=0;
    for(let i of nums){
        maxi |=i
    }
    return backtrack(nums,maxi,0,0);
};

const readline=require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
})

readline.question('Enter the array elements separated by space: ',input=>{
    const nums=input.trim().split(/\s+/).map(Number);
    const result =countMaxOrSubsets(nums);
    console.log("Input array: ",nums);
    console.log("Count of Maximum Bitwise-OR Subsets: ",result);
    readline.close();
})

 