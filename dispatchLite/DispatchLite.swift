public class DispatchObject {

}

public class DispatchQueue : DispatchObject {

}

public class DispatchSource : DispatchObject {

}

@warn_unused_result
@_silgen_name("dispatch_increase_data")
internal func dispatch_increase_data(dq:DispatchQueue, inc:Int) -> Int

