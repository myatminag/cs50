import math

def count_letters(text):
    num_letters = sum(1 for char in text if char.isalpha())
    return num_letters

def count_words(text):
    # Split the text by whitespace and filter out any empty strings
    words = text.split()
    return len(words)

def count_sentences(text):
    num_sentences = sum(1 for char in text if char in '.!?')
    return num_sentences

def main():
    text = input("Text: ")

    words = count_words(text)
    letters = count_letters(text)
    sentences = count_sentences(text)

    av_letter = 100 * (letters / words)
    av_sentence = 100 * (sentences / words)
    result = round(0.0588 * av_letter - 0.296 * av_sentence - 15.8)

    if result > 16:
        print("Grade 16+")
    elif result < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {result}")

if __name__ == "__main__":
    main()
