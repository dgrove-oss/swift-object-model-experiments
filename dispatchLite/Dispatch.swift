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

