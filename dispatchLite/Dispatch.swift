@_exported import Dispatch
import CDispatch

public typealias dispatch_object_t = DispatchObject
public class DispatchObject {
  let cptr:COpaquePointer;

  init (_ np:COpaquePointer) {
    cptr = np
  }
  
  deinit {
	CDispatch.dispatch_release(cptr);
  }
}

public typealias dispatch_queue_t = DispatchQueue
public class DispatchQueue : DispatchObject {
}

public typealias dispatch_source_t = DispatchSource
public class DispatchSource : DispatchObject {
}

public func dispatch_queue_create(x:Int, _ y:Int) -> dispatch_queue_t! {
  return DispatchQueue(CDispatch.dispatch_queue_create(Int32(x), Int32(y)))
}

public func dispatch_source_create(x:Int) -> dispatch_source_t! {
  return DispatchSource(CDispatch.dispatch_source_create(Int32(x)))
}


public func dispatch_suspend(obj:dispatch_object_t) -> Void {
  CDispatch.dispatch_suspend(obj.cptr)  
}

public func dispatch_suspend_q(obj:dispatch_queue_t) {
  CDispatch.dispatch_suspend_q(obj.cptr)  
}

public func dispatch_increase_data(q:dispatch_queue_t, _ x:Int) -> Int {
  return Int(CDispatch.dispatch_increase_data(q.cptr, Int32(x)))
}

public func dispatch_async(q:dispatch_queue_t, _ block:dispatch_block_t) -> Void {
  CDispatch.dispatch_async(q.cptr, block)
}
