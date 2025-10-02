/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let table = {};
    for (let i = 0; i < strs.length; i++) {
        let arrStr = strs[i].split('');
        let key = arrStr.sort();
        if (!table[key]) {
            table[key] = [];
        }
        table[key].push(strs[i]);
    }
    let keys = Object.keys(table);
    return keys.map(e => table[e]);
};