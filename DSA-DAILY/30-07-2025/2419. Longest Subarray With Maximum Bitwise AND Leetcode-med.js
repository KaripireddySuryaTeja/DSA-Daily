/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let ans=0,s=0,maxi=0;
    for(let i of nums){
        if(i>maxi){
            maxi=i;
            s=ans=0;
        }
        if(maxi==i){
            s++;
        }
        else{
            s=0;
        }
        if(ans<s)ans=s;
    }
    return ans;
};
// Node.js input handling
const readline = require('readline');   
const rl = readline.createInterface({
    input: process.stdin,   
    output: process.stdout
});
rl.question('Enter array elements separated by space: ', (input) => {
    const nums = input.trim().split(/\s+/).map(Number);
    const result = longestSubarray(nums);
    console.log('Longest subarray with maximum bitwise AND:', result);
    rl.close();
});
