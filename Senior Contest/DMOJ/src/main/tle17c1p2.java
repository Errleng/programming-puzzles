package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

import static java.lang.Math.abs;

public class tle17c1p2 {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int F = in.nextInt();
        Map<String, Integer> foodEnergy = new HashMap<>();
        for (int i = 0; i < F; ++i) {
            foodEnergy.put(in.next(), in.nextInt());
        }
        int N = in.nextInt();
        Food[] food = new Food[N];
        for (int i = 0; i < N; ++i) {
            food[i] = new Food(in.next(), in.nextInt());
        }
        Arrays.sort(food);
        int wilsonEaten = 0;
        int wilsonEnergy = 0;
        int prevPos = 0;
        for (int i = 0; i < N; ++i) {
            wilsonEnergy -= abs(prevPos - food[i].dist);
            if (wilsonEnergy < 0 && prevPos != food[i].dist) {
                break;
            }
            wilsonEnergy += foodEnergy.get(food[i].name);
            prevPos = food[i].dist;
            ++wilsonEaten;
        }
        out.println(wilsonEaten);
    }
}

class Food implements Comparable<Food> {
    String name;
    int dist;
    Food(String n, int d) {
        name = n;
        dist = d;
    }
    public int compareTo(Food o) {
        return dist - o.dist;
    }
}
