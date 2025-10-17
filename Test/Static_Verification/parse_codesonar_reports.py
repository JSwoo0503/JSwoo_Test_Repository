import json
import csv
import sys
import os

def sarif_to_csv(sarif_file, csv_file):
    with open(sarif_file, encoding="utf-8") as f:
        data = json.load(f)

    results = []
    for run in data.get("runs", []):
        for result in run.get("results", []):
            rule_id = result.get("ruleId", "")
            message = result.get("message", {}).get("text", "")
            level = result.get("level", "")  # warning/severity level
            location = ""
            if "locations" in result:
                loc = result["locations"][0]
                if "physicalLocation" in loc:
                    pl = loc["physicalLocation"]
                    file_uri = pl.get("artifactLocation", {}).get("uri", "")
                    region = pl.get("region", {})
                    start_line = region.get("startLine", "")
                    location = f"{file_uri}:{start_line}"

            results.append([rule_id, message, level, location])

    # CSV 저장
    with open(csv_file, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["Rule", "Message", "Severity", "Location"])
        if results:
            writer.writerows(results)
            print(f"[INFO] Parsed {len(results)} issues from SARIF")
        else:
            writer.writerow(["No issues found", "", "", ""])
            print("[INFO] No issues found in SARIF")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python parse_codesonar_reports.py <input.sarif> <output.csv>")
        sys.exit(1)

    sarif_file = sys.argv[1]
    csv_file = sys.argv[2]

    # 출력 폴더 보장
    os.makedirs(os.path.dirname(csv_file), exist_ok=True)

    sarif_to_csv(sarif_file, csv_file)