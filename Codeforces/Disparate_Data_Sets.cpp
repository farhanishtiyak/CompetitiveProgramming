#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype> // For std::tolower

using namespace std;

// Structure to hold event data
struct Event {
    string event_id;
    string title;
    string acronym;
    string project_code;
    string project_code_3;
    string record_type;
    string parent_id; // To link child to parent

    // Default constructor
    Event() = default;

    Event(string id, string t, string a, string pc, string pc3, string rt)
        : event_id(id), title(t), acronym(a), project_code(pc), project_code_3(pc3), record_type(rt) {}
};

// Helper function to split a CSV line
vector<string> splitCSVLine(const string &line) {
    vector<string> tokens;
    string token;
    bool inQuotes = false;
    for (char c : line) {
        if (c == '"' && (token.empty() || token.back() != '\\')) 
            inQuotes = !inQuotes; // Toggle quote status
        else if (c == ',' && !inQuotes) {
            tokens.push_back(token);
            token.clear(); // Clear token for next field
        } else {
            token += c; // Add character to current token
        }
    }
    tokens.push_back(token); // Push last token
    return tokens;
}

// Comparator for sorting child events
bool compareEvents(const Event &a, const Event &b) {
    if (a.title == b.title) 
        return a.event_id < b.event_id; // Sort by ID if titles are the same
    return a.title < b.title; // Sort by title
}

// Function for case-insensitive string comparison
bool caseInsensitiveEqual(const string &a, const string &b) {
    if (a.size() != b.size()) return false; // Quick check on length
    for (size_t i = 0; i < a.size(); ++i) {
        if (tolower(a[i]) != tolower(b[i])) return false; // Compare characters case-insensitively
    }
    return true;
}

int main() {
    vector<Event> records;
    string line;

    // Read input line by line
    while (getline(cin, line)) {
        vector<string> row = splitCSVLine(line);

        if (row.size() == 6) {
            // Only include records with an acronym and the appropriate record type
            if (!row[2].empty()) {
                // Correctly extract the title by ensuring it handles leading/trailing quotes properly
                string title = row[1];
                if (title.front() == '"' && title.back() == '"') {
                    title = title.substr(1, title.length() - 2); // Remove surrounding quotes
                }
                records.emplace_back(row[0], title, row[2], row[3], row[4], row[5]);
            }
        }
    }

    // Step 1: Separate records into parents and children
    unordered_map<string, Event> parents;
    vector<Event> children;
    for (const auto &record : records) {
        if (record.record_type == "Parent Event") {
            parents[record.event_id] = record;
        } else if (record.record_type == "IEEE Event") {
            children.push_back(record);
        }
    }

    // Step 2: Map children to parents by acronym
    unordered_map<string, vector<Event>> parent_children_map;
    for (auto &child : children) {
        for (auto &parent : parents) {
            // Compare acronyms case-insensitively
            if (caseInsensitiveEqual(parent.second.acronym, child.acronym)) {
                parent_children_map[parent.first].push_back(child);
                child.parent_id = parent.first;  // Set parent_id for output
                break;
            }
        }
    }

    // Step 3: Filter valid parents and assign 3-digit project code based on conditions
    unordered_map<string, Event> valid_parents;
    for (auto &it : parent_children_map) {
        auto parent_id = it.first;
        auto child_list = it.second;
        if (child_list.empty()) continue;  // Skip if no children
        
        unordered_set<string> unique_codes;
        for (const auto &child : child_list) unique_codes.insert(child.project_code_3);

        if (unique_codes.size() == 1) {
            parents[parent_id].project_code_3 = *unique_codes.begin();
        } else {
            parents[parent_id].project_code_3 = "???";
        }

        // Check if the parent has children and is valid
        if (!parents[parent_id].acronym.empty() && unique_codes.size() > 0) {
            valid_parents[parent_id] = parents[parent_id];
        }
    }

    // Step 4: Output sorted results
    vector<Event> output;
    for (const auto &it : valid_parents) {
        auto parent_id = it.first;
        auto parent = it.second;

        // First output the parent event
        output.push_back(parent);

        // Sort children lexicographically by title, then by ID
        vector<Event> children_sorted = parent_children_map[parent_id];
        sort(children_sorted.begin(), children_sorted.end(), compareEvents);

        // Append each child event to the output, including parent ID
        for (auto &child : children_sorted) {
            output.push_back(child);
        }
    }

    // Print the results in CSV format
    for (const auto &event : output) {
        cout << event.event_id << ",\"" << event.title << "\"," << event.acronym << "," 
             << event.project_code << "," << event.project_code_3 << "," << event.record_type;
        if (event.record_type == "IEEE Event") {
            cout << "," << event.parent_id; // Append the parent ID for child records
        }
        cout << endl;
    }

    return 0;
}
