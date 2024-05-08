const findRelativeRanks = (score) => {
    const result = new Array(score.length);
    const mappedIndex = score.map((score, index) => [score, index]);
    mappedIndex.sort((a, b) => b[0] - a[0]);
    const rank = ["Gold Medal", "Silver Medal", "Bronze Medal"];
    for (let i = 0; i < score.length; i++) {
        const index = mappedIndex[i][1];
        if (i <= 2) {
            result[index] = rank[i];
        }
        else {
            result[index] = String(i + 1);
        }

    }
    return result;
};

