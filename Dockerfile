FROM alpine:3.14

ENV PYTHON_VERSION 3.12.6

RUN apk add --no-cache --virtual .build-deps \
        bzip2-dev \
        zlib-dev \
        xz-dev \
    && wget https://www.python.org/ftp/python/$PYTHON_VERSION/Python-$PYTHON_VERSION.tgz \
    && tar xzf Python-$PYTHON_VERSION.tgz \
    && cd Python-$PYTHON_VERSION \
    && ./configure \
    && make -j $(nproc) \
    && make install \
    && rm -rf Python-$PYTHON_VERSION.tgz Python-$PYTHON_VERSION