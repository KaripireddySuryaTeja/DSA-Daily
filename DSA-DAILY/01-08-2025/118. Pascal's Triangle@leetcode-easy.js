/**
 * @param {number} num
 * @return {number[][]}
 */
const generate = num => {
    const dp=[[1]];
    for(let i=1;i<num;i++){
        const prev=dp[dp.length-1];
        const paddedleft= [0, ...prev];
        const paddedright=[...prev,0];
        const curr=paddedleft.map((val,ind) => val + paddedright[ind]);
        dp.push(curr);
    }
    return dp;
};

const readline=require('readline');
const rl=readline.createInterface({
    input: process.stdin,
    output: process.stdout.out
});

rl.question('Enter the number of rows for Pascal\'s Triangle: ', input => {
    const n=parseInt(input);
    const res=generate(n);
    console.log('Pascal\'s Triangle:',res);
    rl.close();
});

const main=()=>{
    const n=readInput();
    const Triangle=generate(n);
    console.log(Triangle);
    Triangle.forEach(row => console.log(row.join(' ')));
}