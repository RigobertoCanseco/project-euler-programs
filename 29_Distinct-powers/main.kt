import java.math.BigDecimal

fun distinctPowers(limit:Int): MutableSet<BigDecimal> {
    var s = mutableSetOf<BigDecimal>()
    (2 until limit+1).forEach{i -> (2 until limit+1).forEach { j -> s.add(BigDecimal(i).pow(j)) }}
    return s
}

fun main(args: Array<String> ) {
    var s = distinctPowers(100)
    println("Elements: ${s.size}")
    println(s)
}
