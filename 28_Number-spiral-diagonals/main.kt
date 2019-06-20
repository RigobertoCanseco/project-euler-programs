
fun sum(limit: Int):Int{
    var numbers: ArrayList<Int> = ArrayList()
    var p:Int = 2
    var c:Int = 1
    numbers.add(c)

    while (p <= limit){
        for(i in 1..4){
            numbers.add(c+p*i)
        }
        c = numbers.last();
        p+=2
    }

    numbers.forEach{ p -> println(p)}

    return numbers.sum()
}
fun main(args: Array<String> ) {
    var s = sum(1001)
    println("Suma: $s")
}
