import unittest
from survey import AnonymousSurvey


class TestSurvey(unittest.TestCase):
    def test_store_single_response(self):
        question = "What language did you first learn to speak"
        my_survery = AnonymousSurvey(question)
        my_survery.store_response("English")
        self.assertIn("English",my_survery.responses)


if __name__ == "__main__":
    unittest.main()