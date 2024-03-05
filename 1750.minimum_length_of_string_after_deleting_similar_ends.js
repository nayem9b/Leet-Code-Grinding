const minimumLength = (s) => {
    let left = 0; right = s.length - 1;
    while (left < right && s[left] === s[right]) {
        let char = s[left];
        while (s[left] == char) {
            left++
        }
        while (right > left && s[right] === char) {
            right--;
        }
    }
    return right-left+1;
};