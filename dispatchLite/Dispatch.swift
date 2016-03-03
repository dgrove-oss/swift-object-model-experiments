@_exported import Dispatch

public class DispatchObject {

  deinit {
    print("DispatchObject::deinit invoked\n");
  }
}

public class DispatchQueue : DispatchObject {

}

public class DispatchSource : DispatchObject {

}

public typealias dispatch_object_t = DispatchObject
public typealias dispatch_queue_t = DispatchQueue
public typealias dispatch_source_t = DispatchSource

/*
@warn_unused_result
@_silgen_name("dispatch_increase_data")
public func dispatch_increase_data(dq:DispatchQueue, _ inc:Int) -> Int

@warn_unused_result
@_silgen_name("dispatch_make_queue")
public func dispatch_make_queue(data1:Int, _ data2:Int) -> DispatchQueue!
*/
