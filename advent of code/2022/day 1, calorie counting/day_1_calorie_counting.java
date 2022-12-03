import java.io.IOException;

import java.util.List;
import java.util.Collections;
import java.util.ArrayList;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

class Day1CalorieCounting {
	public static List<String> readInputFromFile() {
		Path filePath = Paths.get("input.txt");
		Charset charset = StandardCharsets.UTF_8;

		try {
			List<String> input = Files.readAllLines(filePath, charset);
			return input;
		} catch (IOException ex) {
			System.out.format("I/O error: %s%n", ex);
			return null;
		}
	}

	public static void findMostCalories(List<String> input) {
		List<Integer> caloriesOfElves = new ArrayList<Integer>();

		int counter = 0;
		for (String line : input) {
			try {
				counter += Integer.parseInt(line);
			} catch (NumberFormatException nfe) {
				caloriesOfElves.add(counter);
				counter = 0;
			}
		}

		Collections.sort(caloriesOfElves, Collections.reverseOrder());
		int maxCalorie = caloriesOfElves.get(0);
		int sumMostThreeCalories = caloriesOfElves.get(0) + caloriesOfElves.get(1) + caloriesOfElves.get(2);

		System.out.printf("maxCalorie: %d\nsumMostThreeCalories: %d\n", maxCalorie, sumMostThreeCalories);
	}
}

class Solution {
	public static void main(String args[]) {
		List<String> input = Day1CalorieCounting.readInputFromFile();
		Day1CalorieCounting.findMostCalories(input);
	}
}
