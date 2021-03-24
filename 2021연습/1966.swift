let C = Int(readLine()!)!

for _ in 0..<C {
    let inputs: [Int] = readLine()!.split(separator: " ").map { Int(String($0))! }
//    let count = inputs[0]
    let target = inputs[1]
    var q = readLine()!.split(separator: " ").enumerated().map { (index: $0.offset, value: $0.element) }
    var result = 1
    while true {
        let cur = q.removeFirst()
        if q.first(where: { $0.value > cur.value }) == nil {
            if cur.index == target {
                print(result)
                break
            } else {
                result = result + 1
            }
        } else {
            q.append(cur)
        }
    }
}
