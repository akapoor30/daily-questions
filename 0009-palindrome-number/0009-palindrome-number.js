/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0)return false;
    let temp=0;
    let num=x;
    while(x>0){
        temp=temp*10+x%10;
        x=Math.floor(x/10);
    }
    console.log(x%10);
    if(temp===num){
        return 1;
    }
    return 0;
};