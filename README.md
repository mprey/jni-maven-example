# jni-maven-example
A template for using Maven and JNI seamlessly

## Usage

### With a shell

```shell
git clone https://github.com/mprey/jni-maven-example.git
cd jni-maven-example
mvn package
java -cp target/test-jni-1.0-SNAPSHOT.jar org.example.Main
```

### With IntelliJ
1. Clone the repository via CLI or via IntelliJ
2. Open the project in IntelliJ
3. Verify the setting `Delegate IDE build/run actions to Maven` in `Build, Execution, and Deployment -> Build Tools -> Maven -> Runner` is enabled
4. Click the run button (ctrl+R)

## How it works

[maven-antrun-plugin](https://maven.apache.org/plugins/maven-antrun-plugin/) is added to the *compile* phase. Plugin steps:

1. Generates the C/C++ headers for all Java classes in the project using `javac`. The headers are stored in `<jni.codePath>` in the Maven properties.
2. Executes `cmake` to create a Makefile.
3. Executes `make` to compile and build a dynamic library named `<jni.libraryName>`. The library is stored in `target/classes` so it is packaged with the executable Jar.

Once the dynamic library is stored, the `LibraryLoader.java` utitlity class can be used to load the lib automatically.

## Customizing

The following properties exist in `pom.xml` to customize:

```xml
<properties>
    <jni.libraryName>Native</jni.libraryName>
    <jni.codePath>${project.basedir}/src/main/native</jni.codePath>
</properties>
```

Additionally, if the C/C++ code needs to include other libraries, modify the `CMakeLists.txt` as necessary.

## Credits

Inspiration from [jni-maven](https://github.com/gkubisa/jni-maven/).
