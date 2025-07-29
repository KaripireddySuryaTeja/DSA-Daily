/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallestSubarrays = function(nums) {
    const n = nums.length;
    const ans = new Array(n).fill(1);

    for (let i = 0; i < n; i++) {
        let x = nums[i];
        for (let j = i - 1; j >= 0 && (nums[j] | x) !== nums[j]; j--) {
            nums[j] |= x;
            ans[j] = i - j + 1;
        }
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
    const result = smallestSubarrays(nums);
    console.log('Smallest subarrays with maximum bitwise OR:', result);
    rl.close();
});
