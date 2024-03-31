package org.example;

import java.io.IOException;

public class Main {

    static {
        try {
            LibraryLoader.loadLibrary("Native");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private native void sayHello();

    private native void sayHello2();

    public static void main(String[] args) {
        Main main = new Main();
        main.sayHello();
        main.sayHello2();
    }
}