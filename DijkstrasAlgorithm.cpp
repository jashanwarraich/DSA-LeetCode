// Q165 https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/

// Time: O(N+E)+O(N+E)+O(N+E)= Topo sort + Transpose + DFS on topo
// Space: O(N+E) + O(N) + O(N)= new transpose graph + Visited + topo Stack