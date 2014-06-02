import static org.junit.Assert.*;

import org.junit.Test;


public class StringCalculatorClassTest {

	@Test
	public void testCanCallAddWithEmptyString() {
		
		//Setup
		StringCalculatorClass stringCalculatorClass = new StringCalculatorClass();
		
		//Exercise
		int result = stringCalculatorClass.add("");
		
		//Verify
		assertEquals(0, result);
	}

}
