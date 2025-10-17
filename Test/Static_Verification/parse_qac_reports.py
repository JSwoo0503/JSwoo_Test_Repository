#!/usr/bin/env python3
import sys
import csv
import xml.etree.ElementTree as ET

def parse_results(xml_file, output_csv):
    tree = ET.parse(xml_file)
    root = tree.getroot()

    all_results = []

    # 모든 File 요소 순회
    for file_elem in root.findall(".//File"):
        file_path = file_elem.attrib.get("path", "")

        for rule in file_elem.findall(".//Rule"):
            rule_id = rule.attrib.get("id", "")
            rule_desc = rule.attrib.get("text", "")

            for msg in rule.findall("Message"):
                msg_text = msg.attrib.get("text", "").strip()
                sev = msg.attrib.get("severity", "")
                active = msg.attrib.get("active", "")

                all_results.append([
                    file_path,
                    rule_id,
                    msg_text,
                    rule_desc,
                    sev,
                    active
                ])

    # CSV 저장
    with open(output_csv, "w", newline="", encoding="utf-8") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(
            ["File", "Rule", "Message", "RuleDescription", "Severity", "Active"]
        )
        writer.writerows(all_results)

    print(f"CSV 생성 완료: {output_csv}, 총 {len(all_results)} 건")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python parse_qac_reports.py <results_data.xml> <output_csv>")
        sys.exit(1)

    parse_results(sys.argv[1], sys.argv[2])