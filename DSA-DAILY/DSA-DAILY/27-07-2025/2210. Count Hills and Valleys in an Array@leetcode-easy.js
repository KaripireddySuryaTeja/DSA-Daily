/**
 * @param {number[]} nums
 * @return {number}
 */
var countHillValley = function(nums) {
    let res=0,j=0,n=nums.length
    for(let i=1;i<n-1;i++){
        if((nums[j]<nums[i] && nums[i]>nums[i+1])||(nums[j]>nums[i]&&nums[i]<nums[i+1])){
            res++;
            j=i;
        }
    }
    return res;
};

const readline=require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
})

readline.question('Enter the array elements seperated by space:', input=>{
        const nums=input.trim().split(/\s+/).map(Number);
        const result=countHillValley(nums);
        console.log("Input array: ",nums);
        console.log("Number of hills and valleys: ",result);
        readline.close();
}) 