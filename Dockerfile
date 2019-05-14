#
# Dockerfile for testing the repo.
# image : Notes-test:1.0
#

From ubuntu:disco

ENV TEST_DEPS \
		python3 \
		python3-pip \
		cmake

RUN apt-get update && apt-get install -y -q \
		$TEST_DEPS

RUN pip3 install \
		pytest \
		flake8 \
		python-coveralls \
		cpp-coveralls \
		coverage \
		nose \
		tox
