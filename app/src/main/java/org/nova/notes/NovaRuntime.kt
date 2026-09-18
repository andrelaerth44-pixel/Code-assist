package org.nova.notes
class NovaRuntime { init { System.loadLibrary("nova_android") }; external fun nativeVersion(): String; external fun nativeSetText(value:String); external fun nativeGetText():String }
