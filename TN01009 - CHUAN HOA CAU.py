import sys
import re

def normalize_sentences(text):
    """
    Hàm nhận vào một chuỗi text (có thể gồm nhiều dòng), tách thành từng câu theo:
      - Dấu chấm (.), chấm than (!), chấm hỏi (?)
      - Hoặc xuống dòng (\n) cũng coi như kết thúc câu (nếu chưa có dấu ngắt câu).
    Rồi chuẩn hóa mỗi câu:
      1. Chỉ giữ đúng một khoảng trắng giữa các từ.
      2. Viết hoa ký tự đầu, các ký tự khác viết thường.
      3. Nếu câu không kết thúc bằng ., ! hoặc ?, tự động thêm dấu chấm ('.').
    Trả về một list các câu đã chuẩn (mỗi phần tử là một câu đã chuẩn, đã có dấu ngắt câu ở cuối).
    """
    sentences = []
    buffer = []

    def flush_buffer():
        nonlocal buffer
        # Gom buffer thành chuỗi, cắt khoảng trắng đầu/cuối
        raw = ''.join(buffer).strip()
        buffer = []
        if not raw:
            return

        # Xác định dấu ngắt câu cuối cùng (nếu có)
        if raw[-1] in '.!?':
            content = raw[:-1]
            punc = raw[-1]
        else:
            content = raw
            punc = '.'

        # Tách các từ dựa trên 1+ khoảng trắng, rồi nối lại chỉ còn 1 khoảng trắng
        words = re.split(r'\s+', content)
        content_clean = ' '.join(words).lower()

        # Viết hoa ký tự đầu (nếu còn ký tự)
        if content_clean:
            content_clean = content_clean[0].upper() + content_clean[1:]

        sentence = content_clean + punc
        sentences.append(sentence)

    # Duyệt từng ký tự trong text
    for ch in text:
        if ch in '.!?':
            # Gặp dấu ., !, ? -> ghép vào buffer rồi flush thành một câu
            buffer.append(ch)
            flush_buffer()
        elif ch == '\n':
            # Xuống dòng -> coi như kết thúc câu (nếu buffer chưa có dấu ngắt)
            flush_buffer()
        else:
            # Bình thường, gom ký tự vào buffer
            buffer.append(ch)

    # Sau khi duyệt hết, nếu còn buffer thừa (không có dấu ngắt câu ở cuối), flush thêm
    flush_buffer()
    return sentences

if __name__ == "__main__":
    # Đọc toàn bộ input từ stdin
    data = sys.stdin.read()
    # Chuẩn hóa và in ra từng câu một dòng
    for sent in normalize_sentences(data):
        print(sent)
