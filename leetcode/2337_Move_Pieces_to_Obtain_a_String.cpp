class Solution {
public:
    bool canChange(string start, string target) {
        // Queue to store characters and indices from both strings
        queue<pair<char, int>> startQueue, targetQueue;

        // Record non-underscore characters and their indices
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        // If number of pieces don't match, return false
        if (startQueue.size() != targetQueue.size()) return false;

        // Compare each piece's type and position
        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            // Check character match and movement rules
            if (startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex))
                return false;
        }

        return true;
    }
};











//other method 

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        queue<pair<char, int>> startq, targetq;

        // Collect characters and their indices in both strings
        for (int i = 0; i < n; i++) {
            if (start[i] != '_') startq.push({start[i], i});
            if (target[i] != '_') targetq.push({target[i], i});
        }

        // If the number of characters in both queues does not match, return false
        if (startq.size() != targetq.size())
            return false;

        // Validate movements
        while (!startq.empty()) {
            auto [val1, ind1] = startq.front(); startq.pop();
            auto [val2, ind2] = targetq.front(); targetq.pop();

            // Check if characters and their relative positions are valid
            if (val1 != val2) return false; // Characters must match
            if (val1 == 'L' && ind1 < ind2) return false; // 'L' can only move left
            if (val1 == 'R' && ind1 > ind2) return false; // 'R' can only move right
        }

        return true;
    }
};
