var rearrangeArray = function (nums) {

  let res = new Array(nums.length).fill(0), //creating new array with the same length with 0 filled
    pos = 0,                          //taking positive positions on 0 
    neg = 1;                         //taking positive positions on 1

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) {            //iterating through num array and checking it if it positive or not
      res[pos] = nums[i];        //placing the pos number at 0th index
      pos += 2;                 //incrementing the index by 2
    } else {                   //same goes here
      res[neg] = nums[i];
      neg += 2;
    }
  }
  return res;
};
