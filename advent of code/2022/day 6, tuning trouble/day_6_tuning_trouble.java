import java.io.IOException;

import java.util.List;
import java.util.HashSet;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

class TuningTrouble {
	private int charactersBeforeEndOfPacketMaker;
	private int charactersBeforeEndOfMessageMaker;

	private int countCharactersBeforeEndOfSomeMaker(final List<String> input, final int sizePacket) {
		final int initialIndex = sizePacket - 1;
		int lastIndexOfSomeMaker = -1;

		for (int i = initialIndex, n = input.get(0).length(); i < n; i++) {

			int initSubstring = i - initialIndex;
			int endSubstring = initSubstring + sizePacket;
			String substring = input.get(0).substring(initSubstring, endSubstring);

			if (isSubstringLikeASet(substring)) {
				lastIndexOfSomeMaker = i;
				break;
			}
		}
		return lastIndexOfSomeMaker + 1;
	}

	private boolean isSubstringLikeASet(String substring) {
		HashSet<Character> charSet = new HashSet<Character>();
		for (char character : substring.toCharArray())
			if (!charSet.add(character))
				return false;
		return true;
	}

	public TuningTrouble(final List<String> input) {
		this.charactersBeforeEndOfPacketMaker = countCharactersBeforeEndOfSomeMaker(input, 4);
		this.charactersBeforeEndOfMessageMaker = countCharactersBeforeEndOfSomeMaker(input, 14);
		printOutput();
	}

	public void printOutput() {
		System.out.println(charactersBeforeEndOfPacketMaker + "\n" + charactersBeforeEndOfMessageMaker);
	}
}

class Solution {
	public static List<String> readInputFromFile() {
		Path filePath = Paths.get("input.txt");
		Charset charset = StandardCharsets.UTF_8;

		try {
			List<String> input = Files.readAllLines(filePath, charset);
			return input;
		} catch (IOException error) {
			System.out.format("I/O error: %s%n", error);
			return null;
		}
	}

	public static void main(String[] args) {
		final List<String> input = readInputFromFile();
		TuningTrouble TuningTrouble = new TuningTrouble(input);
	}
}
