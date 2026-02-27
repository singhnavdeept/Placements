import java.util.Scanner

fun main() {
    val sc = Scanner(System.`in`)
    
    if (!sc.hasNextInt()) return
    val t = sc.nextInt()
    
    repeat(t) {
        val n = sc.nextInt()
        val mp = mutableMapOf<Int, Int>()
         repeat(n) {
            val x = sc.nextInt()
            mp[x] = mp.getOrDefault(x, 0) + 1
        }
         var cnt = 0
         for (count in mp.values) {
            cnt += count / 2
        }
        
        println(cnt)
    }
}