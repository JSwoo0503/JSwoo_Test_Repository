from __future__ import annotations

import os
import sys
import shutil
from datetime import datetime
from pathlib import Path
from typing import Tuple


def detect_repo_root(script_path: Path) -> Path:
    # script: <repo>/Test/Test_Verification/overwrite_CCASTcfg.py
    # repo_root = script.parents[2]  (.. / ..)
    try:
        return script_path.parents[2]
    except Exception:
        return script_path.resolve().parent


def read_text_smart(p: Path) -> Tuple[str, str]:
    """Try multiple encodings to read the text, and return the used encoding name together."""
    encodings = ["utf-8-sig", "utf-8", "cp949", "euc-kr", "latin-1"]
    last_err = None
    for enc in encodings:
        try:
            return p.read_text(encoding=enc), enc
        except Exception as e:
            last_err = e
    raise RuntimeError(f"Failed to read file: {p} (Last error: {last_err})")


def write_text_crlf(p: Path, content: str, encoding: str = "utf-8") -> None:
    # 모든 줄바꿈을 CRLF로 정규화
    content = content.replace("\r\n", "\n").replace("\r", "\n").replace("\n", "\r\n")
    p.write_text(content, encoding=encoding, newline="")  # 이미 CRLF로 변환됨


def main() -> int:
    script_path = Path(__file__).resolve()
    repo_root = detect_repo_root(script_path)

    # 기본 경로
    default_src = repo_root / "Test" / "Test_Verification" / "CCAST_User.CFG"
    default_dst = repo_root / "CCAST_.CFG"

    # 환경변수로 경로 재정의 가능
    src_path = Path(os.environ.get("CCAST_SOURCE", str(default_src))).resolve()
    dst_path = Path(os.environ.get("CCAST_DEST", str(default_dst))).resolve()

    print(f"[overwrite_CCASTcfg] Repo Root     : {repo_root}")
    print(f"[overwrite_CCASTcfg] Source(Input) : {src_path}")
    print(f"[overwrite_CCASTcfg] Dest (Output) : {dst_path}")

    if not src_path.exists():
        print(f"Source file not found.: {src_path}", file=sys.stderr)
        return 2

    # 대상 디렉토리 보장
    dst_path.parent.mkdir(parents=True, exist_ok=True)

    # 백업 생성 (존재 시)
    if dst_path.exists():
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        backup_path = dst_path.with_suffix(dst_path.suffix + f".bak_{ts}")
        shutil.copy2(dst_path, backup_path)
        print(f"Create an existing file backup: {backup_path}")

    # 읽기 + 쓰기
    try:
        text, used_enc = read_text_smart(src_path)
        write_text_crlf(dst_path, text, encoding="utf-8")
    except Exception as e:
        print(f"Fail: {e}", file=sys.stderr)
        return 3

    # 간단한 리포트
    line_count = text.count("\n") + 1 if text else 0
    print(f"Success: {dst_path.name} (Line Count: {line_count}, Input Encoding: {used_enc}, Save Encoding: utf-8, Line: CRLF)")
    return 0


if __name__ == "__main__":
    sys.exit(main())