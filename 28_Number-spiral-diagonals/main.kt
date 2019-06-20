
fun sum(limit: Int):Int{
    var numbers: ArrayList<Int> = ArrayList()
    var c:Int = 1
    numbers.add(c)

    (2 until limit step 2).forEach{ p ->
        (1 until 5).forEach{i ->numbers.add(c+p*i) }
        c = numbers.last()
    }

    return numbers.sum()
}
fun main(args: Array<String> ) {
    var s = sum(1001)
    println("Suma: $s")
}
