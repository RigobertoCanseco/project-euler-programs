import java.lang.Math.pow

fun power(p:Double): MutableSet<Int>{
    var nums = mutableSetOf<Int>()

    (0 until 10).forEach{i -> (0 until 10).forEach { j -> (0 until 10).forEach { k -> (0 until 10).forEach { l -> (0 until 10).forEach { m -> (0 until 10).forEach { n ->
        var a = "$i$j$k$l$m$n".toInt()
        var b = pow(i.toDouble(), p).toInt() +
                pow(j.toDouble(), p).toInt() +
                pow(k.toDouble(), p).toInt() +
                pow(l.toDouble(), p).toInt() +
                pow(m.toDouble(), p).toInt() +
                pow(n.toDouble(), p).toInt()
        //println("$a, $b")
        if(  b.equals(a) && b > 1)
            nums.add(b)
    }}}}}}

    return nums
}

fun main(args: Array<String> ) {

    var n = power(5.0)
    println(n)
    println("Suma: ${n.sum()}")
}
