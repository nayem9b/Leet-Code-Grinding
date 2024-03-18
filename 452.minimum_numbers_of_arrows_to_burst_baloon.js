const findMinArrowShots = (points) => {
  // Step 1: Sort points array by starting coordinate
  const p = points.sort((a, b) => a[0] - b[0]);
  let stack = []; // Step 2

  // Step 3: Iterate through each balloon's range
  for (let range of p) {
    const slen = stack.length;
    // Step 3a: Check for overlap
    if (slen > 0 && stack[slen - 1][1] >= range[0]) {
      // Step 3b: Overlap found
      const topStack = stack.pop();
      const lastStartPoint = topStack[0];
      const lastEndPoint = topStack[1];
      // Step 3b.i: Pop and determine max start and min end points
      stack.push([
        Math.max(range[0], lastStartPoint),
        Math.min(range[1], lastEndPoint),
      ]); // Step 3b.ii: Push updated range back
    } else {
      // Step 3c: No overlap, push current range onto stack
      stack.push([range[0], range[1]]);
    }
  }
  // Step 4: Return length of stack
  return stack.length;
};
