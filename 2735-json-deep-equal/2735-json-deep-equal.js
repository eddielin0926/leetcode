/**
 * @param {null|boolean|number|string|Array|Object} o1
 * @param {null|boolean|number|string|Array|Object} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    if (o1 === o2) return true;
    if (typeof o1 !== "object" || typeof o2 !== "object" || o1 == null || o2 == null) return false;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;
    const k1 = Object.keys(o1), k2 = Object.keys(o2);
    if (k1.length !== k2.length) return false;
    return k1.every(k => areDeeplyEqual(o1[k], o2[k]));
};