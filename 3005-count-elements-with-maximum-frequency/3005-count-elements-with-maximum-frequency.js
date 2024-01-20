/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function(nums) {
    const vec=new Array(101).fill(0);
  
    for(let ind of nums){
        vec[ind]++;
    }
    
    let maxi=Math.max.apply(null,vec);
    console.log(maxi);
    let ans=0;
    for(let ind = 0;ind<vec.length;ind++){
        if(maxi==vec[ind]){
            ans+=vec[ind];
        }
    }
    return ans;
};