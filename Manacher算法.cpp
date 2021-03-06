//Manacher也是讲的子串的问题
//一个字符串找到最长回文字符串
//回文右边界,实际字符串是加上虚轴的
/** 可能性     i在R外      暴力括
 *             i在R内      (1) i'回文在L,R内 时间复杂度O(1)
 *                         (2) i'回文在L,R外 时间复杂度O(1)
 *                         (3) i'回文左边界与L压线, 从R的又边界继续括
 * 整体时间复杂度为O(N) 
 */
 
 /**
  * eg:
  * 给定一个字符串，添加最少的字符，把这个字符串变成回文字符串
  * 思路：求这条字符串的最长回文串，然后把前面不是回文字符串的子字符串逆序添加到
  * 字符串后面
  * 例如: abc12321 此时最长回文串为12321, 那么把abc逆序，添加到字符串末尾
  * eg: abc12321cba 此时就是添加最少字符形成的回文字符串
  */
