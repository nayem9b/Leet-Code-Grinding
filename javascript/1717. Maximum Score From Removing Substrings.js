var maximumGain = function(s, x, y) {
    function processAB(s, x, y) {
        let stk = [];
        let ans = 0;
        for (let char of s) {
            if (stk.length > 0 && stk[stk.length - 1] === 'a' && char === 'b') {
                stk.pop();
                ans += x;
            } else {
                stk.push(char);
            }
        }
        let a = stk.filter(c => c === 'a').length;
        let b = stk.filter(c => c === 'b').length;
        return Math.min(a, b) * y + ans;
    }

    function processBA(s, x, y) {
        let stk = [];
        let ans = 0;
        for (let char of s) {
            if (stk.length > 0 && stk[stk.length - 1] === 'b' && char === 'a') {
                stk.pop();
                ans += y;
            } else {
                stk.push(char);
            }
        }
        let a = stk.filter(c => c === 'a').length;
        let b = stk.filter(c => c === 'b').length;
        return Math.min(a, b) * x + ans;
    }
    
    let ans = 0;
    const n = s.length;
    for (let i = 0; i < n; i++) {
        if (s[i] !== 'a' && s[i] !== 'b') continue;
        let j = i;
        let t = "";
        while (j < n && (s[j] === 'a' || s[j] === 'b')) {
            t += s[j];
            j++;
        }
        ans += Math.max(processAB(t, x, y), processBA(t, x, y));
        i = j - 1;
    }
    return ans;
};