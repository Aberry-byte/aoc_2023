import java.io.File
import java.io.FileNotFoundException
import java.util.Scanner
import kotlin.math.pow

fun main() {
    var sum: Int = 0
    try {
        val scan = Scanner(File("test_file.txt"))
        while (scan.hasNextLine()) {
            val line = scan.nextLine()
            val cleanedLine = line.slice(8..line.lastIndex)
            val splitLine = cleanedLine.trim().split('|').map { it.trim() }
            val winningNumbers = splitLine[0].split(' ').map { it.trim() }
            val chosenNumbers = splitLine[1]. split(' ').map { it.trim() }
            val overlapNumbers = chosenNumbers.intersect(winningNumbers.toSet())
            sum += getPointCount(overlapNumbers.size)
        }
    } catch (e: FileNotFoundException) {
        e.printStackTrace()
    }
    println(sum)
}

fun getPointCount(overlaps: Int): Int {
    return (2.0.pow(overlaps - 1)).toInt()
}