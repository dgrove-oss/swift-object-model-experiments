@_exported import Dispatch

public typealias dispatch_object_t = DispatchObject
public class DispatchObject {
  let cptr:COpaquePointer;

  init (_ np:COpaquePointer) {
    cptr = np
  }
  
  deinit {
	Dispatch.dispatch_release(cptr);
  }
}

public typealias dispatch_queue_t = DispatchQueue
public class DispatchQueue : DispatchObject {
}

public typealias dispatch_source_t = DispatchSource
public class DispatchSource : DispatchObject {
}

public func dispatch_queue_create(x:Int, _ y:Int) -> dispatch_queue_t! {
  return DispatchQueue(Dispatch.dispatch_queue_create(Int32(x), Int32(y)))
}

public func dispatch_source_create(x:Int) -> dispatch_source_t! {
  return DispatchSource(Dispatch.dispatch_source_create(Int32(x)))
}


public func dispatch_suspend(obj:dispatch_object_t) -> Void {
  Dispatch.dispatch_suspend(obj.cptr)  
}

public func dispatch_suspend_q(obj:dispatch_queue_t) {
  Dispatch.dispatch_suspend_q(obj.cptr)  
}

public func dispatch_increase_data(q:dispatch_queue_t, _ x:Int) -> Int {
  return Int(Dispatch.dispatch_increase_data(q.cptr, Int32(x)))
}

public func dispatch_async(q:dispatch_queue_t, _ block:dispatch_block_t) -> Void {
  Dispatch.dispatch_async(q.cptr, block)
}
