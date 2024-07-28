class Solution:GuessGame() {
    override fun guessNumber(n:Int):Int {
        var left = 0
        var right = n
        
        while(left < right) {
            var mid = left + (right-left)/2
            when(guess(mid)){
                0 -> return mid
                1 -> left = mid+1
                else -> right = mid-1
            }
        }
        
        return left;
    }
}