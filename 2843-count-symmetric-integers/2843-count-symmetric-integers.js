/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */


const isSum = (num) => {
    const arr=[];
    while(num>0){
        arr.push(num%10);
        num = Math.floor(num/10);
    }
    
    if(arr.length%2!=0)return false;
    let leftSum=0;
    let rightSum=0;
    for(let i=0;i<arr.length/2;i++){
        leftSum+=arr[i];
        rightSum+=arr[arr.length-i-1];
    }
    
    if(leftSum==rightSum)return true;
    
    return false;
    
}


var countSymmetricIntegers = function(low, high) {
    let count=0;
    
    for(let i=low;i<=high;i++){
        if(isSum(i))count++;
    }
    
    return count;
};