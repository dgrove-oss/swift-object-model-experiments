public class DispatchObject {

}

public class DispatchQueue : DispatchObject {

}

public class DispatchSource : DispatchObject {

}

@warn_unused_result
@_silgen_name("dispatch_increase_data")
public func dispatch_increase_data(dq:DispatchQueue, _ inc:Int) -> Int

@warn_unused_result
@_silgen_name("dispatch_make_queue")
public func dispatch_make_queue(data1:Int, _ data2:Int) -> DispatchQueue!


