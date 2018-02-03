package newer;
public class Sample_JNI_Test{
	static{
		System.loadLibrary("Sample");
	}

	public static void main(String[] args) {
		Sample_JNI  obj=new Sample_JNI();
		int square=obj.intMethod(100);
		boolean bool=obj.booleanMethod(true);
		String text=obj.stringMethod("JAVA JNI");
		int sum=obj.intArrayMethod(new int[]{1,1,2,3,5,8,13});
		System.out.println("intMethod="+square);
		System.out.println("booleanMethod="+bool);
		System.out.println("stringMethod="+text);
		System.out.println("intArrayMethod="+sum);
	}
}