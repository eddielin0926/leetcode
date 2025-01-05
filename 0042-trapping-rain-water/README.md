<h2><a href="https://leetcode.com/problems/trapping-rain-water">42. Trapping Rain Water</a></h2><h3>Hard</h3><hr><p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;" />
<pre>
<strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<h2>Note</h2>

每一個位置的水量由兩側最高取低的決定，因此水量會等於 `min(leftMax, rightMax) - height[i]`。  

Sol 1. 建表
計算每一個位置的 `leftMax[i]` 和 `rightMax[i]` 然後計算 `min(leftMax[i], rightMax[i])`。

Sol 2. 左右指標
從兩端開始，比較低的那側就瓶頸就先計算並移動。例如，左側最高比右側最高還低，不管中間是否有更高的，水量一定不會高過左側最高，因此該位置的水量就是 `leftMax - height[i]`，左側就要繼續向右移動，反之亦然。
